import syntaxtree.*;
import visitor.*;
import java.util.*;

public class P3 {
   public static void main(String [] args) {
      try {
         Node root = new MiniJavaParser(System.in).Goal();
         ST SymbolTable = new ST();
         root.accept(new GJNoArguDepthFirst<String>(SymbolTable));
         SymbolTable.make();
         // SymbolTable.debug();
         
         root.accept( new GJDepthFirst<String,String>(SymbolTable) , null); 
         
      }
      catch (ParseException e) {
         System.err.println(e);
      }
   }
}
