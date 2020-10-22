import java.util.Random;
import java.util.Scanner;

public class MergeSort {

    void merge(int[] arr, int low, int mid, int high) {
        int i = low;
        int j = mid + 1;
        int k = low;
        int[] resArr = new int[1000];

        while (i <= mid && j <= high) {
            if (arr[i] < arr[j])
                resArr[k++] = arr[i++];
            else
                resArr[k++] = arr[j++];
        }

        while (i <= mid)
            resArr[k++] = arr[i++];
        while (j <= high)
            resArr[k++] = arr[j++];
        for (int x = low; x <= high; x++)
            arr[x] = resArr[x];
    }

    void sort(int[] arr, int low, int high) {
        if (low < high) {
	    int mid = low + (high - low) / 2;
            sort(arr, low, mid);
            sort(arr, mid + 1, high);
            merge(arr, low, mid, high);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements:");
        int n = sc.nextInt();
        int[] arr = new int[n];
        Random gen = new Random();
        for (int i = 0; i < n; i++)
            arr[i] = gen.nextInt(5000);
        System.out.println("Array before sorting:");
        for (int i = 0; i < n; i++)
            System.out.print(arr[i] + "\t");
        
        long startTime = System.nanoTime();
        MergeSort obj = new MergeSort();
        obj.sort(arr, 0, n - 1);
        long stopTime = System.nanoTime();

        long elapsedTime = stopTime - startTime;
        
        System.out.println("\nThe sorted array is:");
        for (int i = 0; i < n; i++)
            System.out.print(arr[i] + "\t");
        
        System.out.println("\nThe time taken to sort the array is "
                         + elapsedTime + " nanoseconds");
        
        sc.close();
    }
}
