package simulation.ConnectionSimulations;

import connection.MessageListener;
import connection.Subscriber;

import java.security.SecureRandom;

public class SensorSubscriberSimulator implements Subscriber<String> {
    SenderThread thread;

    public SensorSubscriberSimulator(){
    }

    @Override
    public void subscribe(String topic) {

    }

    @Override
    public void receive(String topic, String message) {

    }

    @Override
    public void addListener(MessageListener messageListener) {
        thread = new SenderThread(messageListener);
        thread.start();
    }

    @Override
    public void disconnect() {
        thread.interrupt();
    }

    public class SenderThread extends Thread{
        private MessageListener messageListener;
        private int spatialModelSize;

        public SenderThread(MessageListener messageListener){
            this.messageListener = messageListener;
            this.spatialModelSize = 4;
        }

        @Override
        public void run() {
            String message;
            double temp, hum;
            int co2, tvoc;
            double time = 0;
            final SecureRandom rand = new SecureRandom();
            while (!Thread.currentThread().isInterrupted())
            {
                try
                {
                    for (int i = 0; i < spatialModelSize; i++){
                        temp = 25+ rand.nextDouble(8);
                        hum = 10+ rand.nextDouble(40);
                        co2 = 600+ rand.nextInt(100);
                        tvoc = rand.nextInt(400);
                        message = "{ 'id':"+i+",\n" +
                                "   'time':"+time+",\n" +
                                "   'temp':"+temp+",\n" +
                                "   'hum': "+hum+",\n" +
                                "   'co2': "+co2+",\n" +
                                "   'tvoc':"+tvoc+"\n" +
                                "   }";
                        messageListener.messageArrived("", message);
                    }
                    time ++;
                    Thread.sleep(2000);
                }
                catch (InterruptedException ex)
                {
                    Thread.currentThread().interrupt();
                }
            }
        }
    }
}
