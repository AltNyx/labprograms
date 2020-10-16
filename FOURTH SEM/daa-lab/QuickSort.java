import java.util.Scanner;
import java.util.Random;

public class QuickSort {

    int partition(int[] arr, int low, int high) {
        int pivot = arr[low];
        int i = low + 1;
        int j = high;
        while (i < j) {

            while (arr[i] <= pivot && i < high) {
                i++;
            }

            while (arr[j] > pivot) {
                j--;
            }

            if (i < j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

            else {
                int temp = arr[low];
                arr[low] = arr[j];
                arr[j] = temp;
                return j;
            }
        }
        return j;
    }

    void sort (int[] arr, int low, int high) {
        if (low < high) {
            int j = partition(arr, low, high);
            sort(arr, low, j - 1);
            sort(arr, low + 1, high);
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements:");
        int n = sc.nextInt();
        int[] arr = new int[n];
        Random generator = new Random();
        for (int i = 0; i < n; i++) {
            arr[i] = generator.nextInt(5000);
        }

        System.out.println("\nArray before sorting:");
        for(int i = 0; i < n; i++) {
            System.out.print(arr[i] + "\t");
        }

        long startTime = System.nanoTime();

        QuickSort ob = new QuickSort();
        ob.sort(arr, 0, n - 1);

        long stopTime = System.nanoTime();
        double elapseTime = (stopTime - startTime);

        System.out.println("\nThe sorted array is:");

        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + "\t");
        }

        System.out.println("\nThe time taken to sort the array is " + elapseTime + " nano seconds\n");

        sc.close();

    }
}
