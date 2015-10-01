import java.util.Arrays;
 
public class QuickSort
{
    public static void quickSort(int array[], int lowerIndex, int higherIndex) 
    {     
        
    
    
    }
     
    public static void main(String a[])
    {
         
        int[] input = {24,2,45,20,56,75,2,56,99,53,12};
        System.out.println("Unsorted Array "+Arrays.toString(input));

        int length = input.length;
        quickSort(input, 0, length - 1);

        System.out.println("Sorted Array "+Arrays.toString(input));
    }
}
