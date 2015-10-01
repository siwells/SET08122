public class BinarySearch
{
 
    public int binarySearch(int[] data, int key)
    {
         
        int start = 0;
        int end = data.length - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (key == data[mid]) {
                return mid;
            }
            if (key < data[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
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
