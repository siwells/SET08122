import java.util.Arrays;

public class BubbleSort
{
    public static void bubbleSort(int array[])
    {


    }
  
    public static void main(String[] args)
    {
        int[] data = { 4, 37, 9, 6, 23, 55, 34, 0, 1 };
        System.out.println("Unsorted Array "+Arrays.toString(data));
        bubbleSort(data);
        System.out.println("Sorted Array "+Arrays.toString(data));
    }
}
