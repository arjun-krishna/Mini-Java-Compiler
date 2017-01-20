import syntaxtree.*;
import visitor.*;
import java.util.*;

public class P4 {
   public static void main(String [] args) {
      try {
         Node root = new MiniIRParser(System.in).Goal();
         Integer maxTemp = 0;
         HashMap<Integer,Integer> hm = new HashMap<Integer,Integer>();
         hm.put(0,maxTemp);
         root.accept(new GJNoArguDepthFirst(hm));
         Integer initTemp = hm.get(0)+1;
         root.accept(new GJDepthFirst(initTemp),null);
      }
      catch (ParseException e) {
         System.out.println(e.toString());
      }
   }
} 


