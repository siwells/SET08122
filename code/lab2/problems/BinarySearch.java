public class BinarySearch
{
 
    public int binarySearch(int[] data, int key)
    {
         

    }
  
    public static void main(String[] args)
    {
         
        BinarySearch bs = new BinarySearch();
        int[] data = {12, 34, 65, 18, 3, 122, 54, 76};
        int key = 122;
        int result = bs.binarySearch(data, key);

        if (result == -1)
            System.out.println("Key not found in array");
        else
            System.out.println("Key "+key+" found at index: "+result);
    }
}
