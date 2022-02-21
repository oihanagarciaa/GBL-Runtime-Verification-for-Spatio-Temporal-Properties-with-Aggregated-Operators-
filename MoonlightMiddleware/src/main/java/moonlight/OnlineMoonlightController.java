package moonlight;

import eu.quanticol.moonlight.domain.AbstractInterval;
import eu.quanticol.moonlight.domain.BooleanDomain;
import eu.quanticol.moonlight.domain.DoubleDistance;
import eu.quanticol.moonlight.formula.AtomicFormula;
import eu.quanticol.moonlight.formula.Formula;
import eu.quanticol.moonlight.formula.Parameters;
import eu.quanticol.moonlight.io.MoonLightRecord;
import eu.quanticol.moonlight.monitoring.online.OnlineSpaceTimeMonitor;
import eu.quanticol.moonlight.space.DistanceStructure;
import eu.quanticol.moonlight.space.LocationService;
import eu.quanticol.moonlight.space.SpatialModel;
import eu.quanticol.moonlight.util.Utils;
import moonlight.model.OnlineFormulas;
import moonlight.model.SpatialModelSetup;

import java.util.HashMap;
import java.util.Map;
import java.util.function.Function;

public class OnlineMoonlightController{
    final int SIZE = 6;
    SpatialModel<Double> city;
    LocationService<Double, Double> locSvc;
    OnlineSpaceTimeMonitor<Double, MoonLightRecord, Boolean> onlineMonitor;
    OnlineFormulas formulas;

    public OnlineMoonlightController() {
        formulas = new OnlineFormulas(city);
        city = SpatialModelSetup.buildSpatialModel(SIZE);
        locSvc = Utils.createLocServiceStatic(0, 1, 10, city);
    }

    public static Formula formula() {
        Formula controlPeople = new AtomicFormula("manyPeople");
        /*Formula isSchool = new AtomicFormula("isSchool");
        Formula noiseLevel = new AtomicFormula("noiseLevel");
        Formula noiseNearby = new EscapeFormula("distance", noiseLevel);

        return new OrFormula(new NegationFormula(isSchool), noiseNearby);*/
        return controlPeople;
    }

    public OnlineSpaceTimeMonitor<Double, MoonLightRecord, Boolean> onlineMonitorInit(Formula f){
        Map<String, Function<MoonLightRecord, AbstractInterval<Boolean>>> atoms = formulas.setOnlineAtoms();

        onlineMonitor = new OnlineSpaceTimeMonitor<>(f, SIZE, new BooleanDomain(),
                locSvc, atoms, formulas.getDistanceFunctions());

        return onlineMonitor;
    }


}
