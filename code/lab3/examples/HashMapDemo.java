import java.util.*;

public class HashMapDemo
{
    public static void main(String[] args)
    {
        // Create a new HashMap to store our phonebook entries
        HashMap<String, Object> phonebook = new HashMap<String,Object>();
       
        // Add some entries to the phonebook
        phonebook.put("Simon", "01123-123123");
        phonebook.put("Thom", "01123-321321");
        phonebook.put("Lee", "01123-323323");

        Set set = phonebook.entrySet();

        // Iterate over all entries
        Iterator i = set.iterator();
        while(i.hasNext())
        {
            Map.Entry ent = (Map.Entry)i.next();
            System.out.println(ent.getKey()+"::"+ent.getValue());
        }


        // Retrieve value for a single Key
        String phone = (String)phonebook.get("Simon");

        // To set a new value for a key, just provide the new value
        // just like adding a new entry
        phonebook.put("Simon", "01123-313212");

        // Display the changes again
        i = set.iterator();
        while(i.hasNext())
        {
            Map.Entry ent = (Map.Entry)i.next();
            System.out.println(ent.getKey()+"::"+ent.getValue());
        }

    }
}

