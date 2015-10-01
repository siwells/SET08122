import java.util.Arrays;

public class SelectionSort
{
    public static void selectionSort(int[] arr)
    {  
        for(int outer = 0; outer<arr.length-1; outer++)
        {
            int min_idx=outer;
            for(int inner = outer; inner<arr.length; inner++)
                if(arr[inner] < arr[min_idx]) {min_idx = inner;}
            int tmp = arr[outer];
            arr[outer] = arr[min_idx];
            arr[min_idx] = tmp;
            // Uncomment the following to see the array after each iteration of sorting:
            System.out.println("iteration:"+outer+" min:"+arr[outer]+" "+Arrays.toString(arr));
        }
    }
     
    public static void main(String[] args)
    {
        int[] data = {10,34,2,56,7,67,88,42};
        System.out.println("Unsorted Array "+Arrays.toString(data));
        selectionSort(data);
        System.out.println("Sorted Array "+Arrays.toString(data));
    }
}
