import java.util.Arrays;

public class InsertionSort
{   
    public static void insertionSort(int array[])
    {


    }

    public static void main(String[] args)
    {
         
        int[] data = { 4, 2, 9, 6, 23, 12, 34, 0, 1 };
        System.out.println("Unsorted Array "+Arrays.toString(data));
        insertionSort(data);
        System.out.println("Sorted Array "+Arrays.toString(data));
    }

}
