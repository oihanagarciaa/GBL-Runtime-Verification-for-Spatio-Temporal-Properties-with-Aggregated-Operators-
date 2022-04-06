package builders;

import org.eclipse.paho.client.mqttv3.MqttException;
import services.SensorService;
import services.Service;
import subscriber.ConnType;
import subscriber.MQTTSubscriber;

public class SensorsServiceBuilder {
    private Service service;
    private String broker;
    private String topic;
    private String username;
    private String password;
    private ConnType connectionType;
    private Class messageClass;

    public SensorsServiceBuilder(ConnType connection,
                                 String broker,
                                 String topic,
                                 String username,
                                 String password,
                                 Class messageClass) {
        this.connectionType = connection;
        this.broker = broker;
        this.topic = topic;
        this.username = username;
        this.password = password;
        this.messageClass = messageClass;
    }

    private void initializeService() {
        if(connectionType == ConnType.MQTT) {
            try {
                service = new SensorService(new MQTTSubscriber(
                        broker, topic, username, password), messageClass);
            } catch (MqttException e) {
                throw new UnsupportedOperationException("MQTT has failed");
            }
        }else if (connectionType == ConnType.REST){
            throw new UnsupportedOperationException("Not supported connection type");
        }
        else {
            throw new UnsupportedOperationException("Not supported connection type");
        }
        service.init();
    }

    public boolean run() {
        try {
            initializeService();
            return true;
        } catch (UnsupportedOperationException e) {
            return false;
        }
    }

    public Service getService() {
        return service;
    }
}
