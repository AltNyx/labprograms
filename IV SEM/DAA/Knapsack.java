import java.util.Scanner;

public class Knapsack {
    void sort(float[] weight, float[] ratio, int n) {
        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < n - i - 1; j++) {
                if(ratio[j] < ratio[j+1]) {
                    float temp = weight[j];
                    weight[j] = weight[j+1];
                    weight[j+1] = temp;

                    temp = ratio[j];
                    ratio[j] = ratio[j+1];
                    ratio[j+1] = temp;
                }
            }
        }
    }

    float maxProfit(float[] weight, float[] ratio, int n, int weight_lim) {
        float profit = 0;
        float[] x = new float[n];
        int rem_weight = weight_lim;
        int i;
        for(i = 0; i < n; i++) {
            if(rem_weight == 0)
                break;
            if(weight[i] < rem_weight) {
                profit += weight[i] * ratio[i];
                x[i] = 1;
                rem_weight -= weight[i];
            } else {
                profit += rem_weight * ratio[i];
                x[i] = rem_weight / weight[i];
                rem_weight = 0;
            }
        }
        while(i < n) {
            x[i] = 0;
            i++;
        }
        System.out.println("\nThe result is ");
        System.out.print("[");
        int j;
        for(j = 0; j < n - 1; j++)
            System.out.print(x[j] + ", ");
        System.out.print(x[j] + "]");
        return profit;    
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        //read number of items
        System.out.print("Enter number of items:");
        int n = sc.nextInt();
        float[] profit = new float[n];
        float[] weight = new float[n];
        float[] ratio = new float[n];
        //read profit arr
        System.out.println("Enter the profit and weight for all items:");
        for(int i = 0; i < n; i++) {
            System.out.print("Enter profit:");
            profit[i] = sc.nextFloat();
            System.out.print("Enter weight:");
            weight[i] = sc.nextFloat();
            ratio[i] = profit[i] / weight[i];
        }
        System.out.print("Enter maximum weight capacity:");
        int max_weight = sc.nextInt();

        System.out.println("\nInformation about knapsack problem are");
        System.out.println("ITEM\tWEIGHT\tPROFIT\tRATIO");
        for(int i = 0; i < n; i++)
            System.out.println(i + 1 + "\t" + weight[i] + "\t" + profit[i] + "\t" + ratio[i]);
        System.out.println("\nCapacity = " + max_weight);

        Knapsack obj = new Knapsack();
        obj.sort(weight, ratio, n);

        System.out.println("\nAfter sorting based on ratio in descending order:");
        for(int i = 0; i < n; i++)
            System.out.println(i + 1 + "\t" + weight[i] + "\t"+ (weight[i] * ratio[i]) + "\t" + ratio[i]);
        float max_profit = obj.maxProfit(weight, ratio, n, max_weight);
        System.out.println("\n\nThe maximum profit that can be obtained is " + max_profit);

        sc.close();
    }
}