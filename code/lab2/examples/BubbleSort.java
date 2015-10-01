import java.util.Arrays;

public class BubbleSort
{
    public static void bubbleSort(int array[])
    {
        int n = array.length;
        int k;
        int temp;
        for (int m = n; m >= 0; m--) {
            for (int i = 0; i < n - 1; i++) {
                k = i + 1;
                if (array[i] > array[k]) {
                    temp = array[i];
                    array[i] = array[k];
                    array[k] = temp;
                }
            }
            System.out.println(Arrays.toString(array));
        }
    }
  
    public static void main(String[] args)
    {
        int[] data = { 4, 37, 9, 6, 23, 55, 34, 0, 1 };
        System.out.println("Unsorted Array "+Arrays.toString(data));
        bubbleSort(data);
        System.out.println("Sorted Array "+Arrays.toString(data));
    }
}
