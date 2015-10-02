import java.util.*;

public class HashTableDemo
{
    public static void main(String[] args)
    {
        // Create a new Hashtable to store our phonebook
        Hashtable<String,Object> phonebook = new Hashtable<String,Object>();
       
        // Add some entries to the phonebook
        phonebook.put("Simon", "01123-123123");
        phonebook.put("Thom", "01123-321321");
        phonebook.put("Lee", "01123-323323");

        Enumeration names = phonebook.keys();

        // Iterate over all entries
        String name;
        while(names.hasMoreElements())
        {
            name = (String) names.nextElement();
            System.out.println(name+": "+phonebook.get(name));
        }

        // Retrieve a single value for a given key
        String phone = (String)phonebook.get("Simon");
       
        // Update a key:value pair with a new value 
        phonebook.put("Simon", "01123-313212");

        // Display the changes again
        names = phonebook.keys();
        while(names.hasMoreElements())
        {
            name = (String) names.nextElement();
            System.out.println(name+": "+phonebook.get(name));
        }

    }
}
