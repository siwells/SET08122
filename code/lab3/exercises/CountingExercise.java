import java.util.*; 
import java.io.*; 

public class CountingExercise
{
    static public void main(String[] args)
    {
        if (args.length < 1)
        {
            System.out.println("USAGE: java CountWordsFile <filename>");
        }
        else
        {
            String delim = " \t\n.,:;?!-/()[]\"\'";
            String filename = args[0];
            String line = null;
            int count = 0;
            try
            {
                FileReader fR = new FileReader(filename);
                BufferedReader bR = new BufferedReader(fR);

                while((line = bR.readLine()) != null)
                {
                    StringTokenizer strTok = new StringTokenizer(line,delim);
                    String tmpStr = null;
                    while(strTok.hasMoreTokens())
                    {
                        count++;
                        tmpStr = strTok.nextToken();
                        System.out.println(tmpStr);
                    }
                }
                System.out.println("Total number of words: "+count);
            }
            catch(FileNotFoundException ex){ System.out.println("File Not Found"); }
            catch(IOException ex){ System.out.println("An IOException :D"); }
        }
    }
}
