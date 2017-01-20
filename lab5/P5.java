import syntaxtree.*;
import visitor.*;
import java.util.*;

public class P5 {
   public static void main(String [] args) {
      try {
         Node root = new microIRParser(System.in).Goal();

         HashMap<String,Integer> labels = new HashMap<String,Integer>();
         root.accept(new GetLabels(labels));     // To get the target labels in the code // need for Liveliness analysis
         // System.out.println(labels);

         RegAllocInfo info = new RegAllocInfo();
         root.accept(new RegAlloc(info,labels),null);
         // info.debug();

         // printing miniRA
         root.accept(new printMiniRA(info),null);

      }
      catch (ParseException e) {
         System.out.println(e.toString());
      }
   }
} 


