//package uk.ac.napier.set09117.lab2;
 
public class LinearSearch
{
 
    public static int linearSearch(int[] arr, int key)
    {
         
    }
     
    public static void main(String[] args)
    {
         
        int[] data= {223,4,61,347,14,2,1,467,12};
        int key = 347;
        int result = linearSearch(data, key);

        if (result == -1)
            System.out.println("Key not found in array");
        else
            System.out.println("Key "+key+" found at index: "+result);
    }
}

