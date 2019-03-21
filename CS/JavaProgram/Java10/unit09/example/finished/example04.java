public class example04 {

    public static void main(String[] args) {
        example03 tv1 = new example03();
        tv1.turnOn();
        tv1.setChannel(30);
        tv1.setVolume(3);

        example03 tv2 = new example03();
        tv2.turnOn();
        tv2.channelUp();
        tv2.channelUp();
        tv2.volumeUp();

        System.out.println("tv1's channel is " + tv1.channel + " and volume level is " + tv1.volumeLevel);
        System.out.println("tv2's channel is " + tv2.channel + " and volume level is " + tv2.volumeLevel);
    }

}

