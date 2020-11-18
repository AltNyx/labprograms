package prog5;

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
            System.out.print(i + 1 + "\t");
            System.out.print(packets[i] + "\t\t");
            bucketCount = netBucketCount + packets[i];
            if (bucketCount <= bucketSize) {
                printDetails("Accepted");
            } else {
                bucketCount = netBucketCount;
                printDetails("Rejected");
            }
        }
        while (netBucketCount != 0) {
            System.out.print(++i + "\t");
            bucketCount = netBucketCount;
            System.out.print("-" + "\t\t");
            printDetails("Accepted");
        }
        System.out.println("--------------------------------------------------------------------------------------");
        sc.close();
    }

    static void printDetails(String status) {
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