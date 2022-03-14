package dataStorages;

import eu.quanticol.moonlight.domain.AbstractInterval;
import eu.quanticol.moonlight.domain.BooleanDomain;
import eu.quanticol.moonlight.domain.DoubleDistance;
import eu.quanticol.moonlight.formula.*;
import eu.quanticol.moonlight.io.MoonLightRecord;
import eu.quanticol.moonlight.monitoring.online.OnlineSpaceTimeMonitor;
import eu.quanticol.moonlight.signal.DataHandler;
import eu.quanticol.moonlight.signal.EnumerationHandler;
import eu.quanticol.moonlight.signal.RecordHandler;
import eu.quanticol.moonlight.signal.Segment;
import eu.quanticol.moonlight.signal.online.SpaceTimeSignal;
import eu.quanticol.moonlight.signal.online.TimeChain;
import eu.quanticol.moonlight.signal.online.Update;
import eu.quanticol.moonlight.space.DistanceStructure;
import eu.quanticol.moonlight.space.LocationService;
import eu.quanticol.moonlight.space.SpatialModel;
import eu.quanticol.moonlight.util.Pair;
import eu.quanticol.moonlight.util.Stopwatch;
import eu.quanticol.moonlight.util.Utils;

import java.util.*;
import java.util.function.Function;

public class DELETEOnlineCitySignalDefinition {
    int size;
    final double SECURITY_DISTANCE = 7;
    final int MAX_PERSONS = 24;
    final int MAX_DECIBELS = 70;
    List<String> places;
    List<Integer> noiseLevel1, noiseLevel2;
    Random rand;
    SpatialModel<Double> city;

    private static Map<String,
            Function<Parameters,
                    Function<MoonLightRecord, Boolean>>>
            atomicFormulas;

    private static HashMap<String, Function<SpatialModel<Double>,
            DistanceStructure<Double, ?>>> distanceFunctions;

    private static LocationService<Double, Double> locSvc;

    public DELETEOnlineCitySignalDefinition(){
        this.size = 6;
        places = Arrays.asList("Hospital", "School", "MetroStop", "School", "MainSquare", "BusStop");
        noiseLevel1 = Arrays.asList(60, 60, 40, 50, 60, 60);
        noiseLevel2 = Arrays.asList(80, 80, 80, 80, 80, 80);
        rand = new Random();

        HashMap<Pair<Integer, Integer>, Double> cityMap = new HashMap<>();
        cityMap.put(new Pair<>(0, 2), 4.0);
        cityMap.put(new Pair<>(2, 0), 4.0);
        cityMap.put(new Pair<>(2, 3), 8.0);
        cityMap.put(new Pair<>(0, 4), 7.0);
        cityMap.put(new Pair<>(0, 5), 25.0);
        cityMap.put(new Pair<>(2, 4), 5.0);
        cityMap.put(new Pair<>(4, 2), 5.0);
        cityMap.put(new Pair<>(4, 5), 9.0);
        cityMap.put(new Pair<>(1, 4), 14.0);
        cityMap.put(new Pair<>(1, 5), 19.0);
        city = Utils.createSpatialModel(size, cityMap);

        locSvc = Utils.createLocServiceStatic(0, 1, 10, city);
        setAtomicFormulas();
        setDistanceFunctions();

        Formula noiseNearbySchool = formula();
        System.out.println("Check online");
        checkOnline(noiseNearbySchool);
    }

    private void checkOnline(Formula f) {
        Stopwatch rec = Stopwatch.start();

        OnlineSpaceTimeMonitor<Double, MoonLightRecord, Boolean> m =
                onlineMonitorInit(f);

        /*ALDATUTAKOA*/
        RecordHandler factory = new RecordHandler(new EnumerationHandler<>(String.class, places.toArray(new String[0])), DataHandler.INTEGER, DataHandler.INTEGER);
        List<MoonLightRecord> signalSP = new ArrayList<MoonLightRecord>();
        for (int i = 0; i < size; i++) {
            signalSP.add(factory.fromObjectArray(places.get(i), noiseLevel1.get(i), rand.nextInt(45)));
        }

        TimeChain<Double, List<MoonLightRecord>> timeChain = new TimeChain<>(20.0);
        timeChain.add(new Segment<>(4.0, signalSP));
        m.monitor(timeChain);

        List<MoonLightRecord> signalSP2 = new ArrayList<MoonLightRecord>();
        signalSP2.add(factory.fromObjectArray("", null, null));
        for (int i = 1; i < size; i++) {
            signalSP2.add(factory.fromObjectArray(places.get(i), noiseLevel2.get(i), 3));
        }

        TimeChain<Double, List<MoonLightRecord>> timeChain2 = new TimeChain<>(Double.MAX_VALUE);
        timeChain2.add(new Segment<>(11.0, signalSP2));
        SpaceTimeSignal<Double, AbstractInterval<Boolean>> result = m.monitor(timeChain2);
        System.out.println(0 +"------"+ result.getValueAt(0.0));
        System.out.println(4 +"------"+ result.getValueAt(4.0));
        System.out.println(11 +"------"+ result.getValueAt(11.0));
        System.out.println(13 +"------"+ result.getValueAt(13.0));


        //updates.forEach(m::monitor);
        rec.stop();
        System.out.println(rec.getDuration());

        /*ALDATUTAKOA*/
    }

    private OnlineSpaceTimeMonitor<Double, MoonLightRecord, Boolean> onlineMonitorInit(Formula f) {
        Map<String, Function<MoonLightRecord, AbstractInterval<Boolean>>> atoms = setOnlineAtoms();

        return new OnlineSpaceTimeMonitor<>(f, size, new BooleanDomain(),
                locSvc, atoms, distanceFunctions);
    }

    private  Map<String, Function<MoonLightRecord, AbstractInterval<Boolean>>> setOnlineAtoms() {
        Map<String, Function<MoonLightRecord, AbstractInterval<Boolean>>> atoms = new HashMap<>();
        atoms.put("noiseLevel", a -> booleanInterval(a.get(1, Integer.class)< MAX_DECIBELS));
        atoms.put("isSchool", a -> booleanInterval("School".equals(a.get(0, String.class))));
        atoms.put("manyPeople", a -> booleanInterval(a.get(2, Integer.class) < MAX_PERSONS));
        return atoms;
    }

    private static AbstractInterval<Boolean> booleanInterval(boolean cond) {
        return cond ? new AbstractInterval<>(true, true) :
                new AbstractInterval<>(false, false);
    }

    private void setDistanceFunctions() {
        distanceFunctions = new HashMap<>();
        distanceFunctions.put("distance",
                m -> new DistanceStructure<Double, Double>(x -> x,
                        new DoubleDistance(), SECURITY_DISTANCE, Double.MAX_VALUE, city));
    }

    private void setAtomicFormulas() {
        atomicFormulas = new HashMap<>();
        atomicFormulas.put("noiseLevel", par -> a -> a.get(1, Integer.class)< MAX_DECIBELS);
        atomicFormulas.put("isSchool", par -> a -> "School".equals(a.get(0, String.class)));
        atomicFormulas.put("manyPeople", par -> a -> a.get(2, Integer.class) < MAX_PERSONS);
    }

    private static Formula formula() {
        Formula noiseLevel = new AtomicFormula("noiseLevel");
        Formula isSchool = new AtomicFormula("isSchool");
        Formula noiseNearby = new EscapeFormula("distance", noiseLevel);
        //return new OrFormula(new NegationFormula(isSchool), noiseNearby);
        return noiseLevel;
        //return new EscapeFormula("distance", noiseLevel);
    }

    public static void main(String[] args) {
        DELETEOnlineCitySignalDefinition p = new DELETEOnlineCitySignalDefinition();
    }
}