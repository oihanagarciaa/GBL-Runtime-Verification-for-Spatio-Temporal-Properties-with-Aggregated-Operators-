package controller;

import eu.quanticol.moonlight.domain.AbstractInterval;
import eu.quanticol.moonlight.formula.Formula;
import eu.quanticol.moonlight.io.MoonLightRecord;
import eu.quanticol.moonlight.space.DistanceStructure;
import eu.quanticol.moonlight.space.SpatialModel;
import org.junit.jupiter.api.Test;
import org.junit.runner.RunWith;
import org.mockito.junit.MockitoJUnitRunner;
import services.MonitorType;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.function.Function;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.mockito.Mockito.*;

@RunWith(MockitoJUnitRunner.class)
class MainControllerTest {

    @Test
    void basicControllerInit() {
        Controller controller = controllerInit();

        assertTrue(controller.run());
    }

    @Test
    void testTypicalDataReceived() {
        MainController controller = controllerInit();
        MainController spy = spy(controller);

        spy.run();

        String expectedResult = "test";
        List<String> l = new ArrayList<>();
        l.add("test");
        doReturn(l).when(spy).getResults();

        assertEquals(expectedResult, spy.getResults().get(0));
    }

    private MainController controllerInit() {
        MainController controller = new MainController();
        String sourceId = "tcp://localhost:1883";
        ConnType connType = ConnType.MQTT;
        MonitorType monitorType = MonitorType.ONLINE_MOONLIGHT;
        Formula f = mock(Formula.class);
        SpatialModel<Double> model = mock(SpatialModel.class);
        Map<String, Function<MoonLightRecord, AbstractInterval<Boolean>>> atoms = mock(Map.class);
        HashMap<String, Function<SpatialModel<Double>, DistanceStructure<Double, ?>>> distance = mock(HashMap.class);

        controller.setDataSource(sourceId);
        controller.setConnectionType(connType);
        controller.setMonitorType(monitorType);
        controller.setFormula(f);
        controller.setSpatialModel(model);
        controller.setAtomicFormulas(atoms);
        controller.setDistanceFunctions(distance);
        return controller;
    }
}