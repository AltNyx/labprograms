import java.util.Scanner;

public class LeakyBucket {

    static int bucketCount, bucketSize, i;
    static int outputRate, arrivals;
    static int netBucketCount = 0;
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter number off arrivals: ");
        arrivals = sc.nextInt();
        int[] packets = new int[arrivals];

        System.out.print("Enter the bucket size: ");
        bucketSize = sc.nextInt();

        System.out.print("Enter the output rate: ");
        outputRate = sc.nextInt();

        System.out.print("Enter number of packets arrived at each second: ");
        for (i = 0; i < arrivals; i++) {
            packets[i] = sc.nextInt();
        }

        System.out.println("--------------------------------------------------------------------------------------");
        System.out.println("Second\tNumPackets\tBucketCount\tStatus\t\tPacketsSent\tNetBucketCount");
        System.out.println("--------------------------------------------------------------------------------------");

        for (i = 0; i < arrivals; i++) {
            bucketCount = netBucketCount + packets[i];
            if (bucketCount <= bucketSize) {
                printDetails(i, packets[i], "Accepted");
            } else {
                bucketCount = netBucketCount;
                printDetails(i, packets[i], "Rejected");
            }
        }

        while (netBucketCount != 0) {
            bucketCount = netBucketCount;
            printDetails(++i, 0, "Accepted");
        }
        System.out.println("--------------------------------------------------------------------------------------");
        sc.close();
    }

    static void printDetails(int interval, int numPackets, String status) {
        System.out.print(interval + "\t");
        System.out.print(numPackets + "\t\t");
        System.out.print(bucketCount + "\t\t");
        System.out.print(status + "\t");
        System.out.print(min(bucketCount, outputRate) + "\t\t");
        netBucketCount = sub(bucketCount, outputRate);
        System.out.println(netBucketCount);
    }

    static int sub(int bucketCount, int outputRate) {
        return (bucketCount > outputRate) ? (bucketCount - outputRate) : 0;
    }

    static int min(int bucketCount, int outputRate) {
        return (bucketCount < outputRate) ? bucketCount : outputRate;
    }
}