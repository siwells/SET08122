import java.util.Arrays;
 
public class QuickSort
{
    public static void quickSort(int array[], int lowerIndex, int higherIndex) 
    {     
        int i = lowerIndex;
        int j = higherIndex;
        // calculate pivot number, I am taking pivot as middle index number
        int pivot = array[lowerIndex+(higherIndex-lowerIndex)/2];
        // Divide into two arrays
        while (i <= j)
        {
            /*
             * In each iteration, we will identify a number from left side which 
             * is greater then the pivot value, and also we will identify a number 
             * from right side which is less then the pivot value. Once the search 
             * is done, then we exchange both numbers.
             */
            while (array[i] < pivot) { i++; }
            while (array[j] > pivot) { j--; }
            if (i <= j) 
            {
                //exchangeNumbers(i, j);
                
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;

                //move index to next position on both sides
                i++;
                j--;
            }
        }
        // call quickSort() method recursively
        if (lowerIndex < j)
            quickSort(array, lowerIndex, j);
        if (i < higherIndex)
            quickSort(array, i, higherIndex);
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
