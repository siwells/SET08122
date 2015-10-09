import java.util.List;
import java.util.ArrayList;

public class Lexer
{
    public static enum Type
    {
        LPAREN, RPAREN, ATOM;
    }

    public static class Token
    {
        public final Type t;
        public final String c;
        public Token(Type t, String c)
        {
            this.t = t;
            this.c = c;
        }
        public String toString()
        {
            if(t == Type.ATOM)
            {
                return "ATOM<"+c+">";
            }
            return t.toString();
        }
    }

    public static String getAtom(String s, int i)
    {
        int j=i;
        for( ; j<s.length(); )
        {
            if(Character.isLetter(s.charAt(j)))
            {
                j++;
            }
            else
            {
                return s.substring(i,j);
            }
        }
        return s.substring(i,j);
    }

    public static List<Token> lex(String input)
    {
        List<Token> result = new ArrayList<Token>();

        for(int i=0; i<input.length();)
        {
            switch(input.charAt(i))
            {
                case '(':
                    result.add(new Token(Type.LPAREN, "("));
                    i++;
                    break;
                case ')':
                    result.add(new Token(Type.RPAREN, ")"));
                    i++;
                    break;
                default:
                    if(Character.isWhitespace(input.charAt(i)))
                    {
                        i++;
                    }
                    else
                    {
                        String atom = getAtom(input, i);
                        i += atom.length();
                        result.add(new Token(Type.ATOM, atom));
                    }
                    break;
            }
        }
        return result;
    }

    public static void main(String[] args)
    {
        if(args.length < 1)
        {
            System.out.println("Usage: java Lexer \"  \"");
            return;
        }
        else
        {
            List<Token> tokens = lex(args[0]);
            for(Token t : tokens)
            {
                System.out.println(t);
            }
        }
    }
}
