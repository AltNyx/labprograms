import java.util.Scanner;

public class SubsetSum {

    public static void printSubset(int[] set, int[] solution, int sum) {
        int i;
        String subset = "";
        System.out.println("\nSubset found");
        for(i = 0; i < solution.length; i++) {
            if(solution[i] == 1) {
                subset += (Integer.toString(set[i]) + " ");
            }
        }
        System.out.print("[" + subset.trim() + "]");
    }

    public static void findSubset(int[] set, int currSum, int sum, int index, int[] solution) {
        if (currSum == sum) {
            printSubset(set, solution, sum);
        } else if (index == set.length) {
            return;
        } else {
            currSum += set[index];
            solution[index] = 1;
            findSubset(set, currSum, sum, index + 1, solution);
            currSum -= set[index];
            solution[index] = 0;
            findSubset(set, currSum, sum, index + 1, solution);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        int[] set = new int[n];
        int[] solution = new int[n];
        System.out.println("Enter the elements: ");
        for(int i = 0; i < n; i++) {
            set[i] = sc.nextInt();
        }
        System.out.print("Enter target sum: ");
        int target = sc.nextInt();
        findSubset(set, 0, target, 0, solution);
        sc.close();
    }
}