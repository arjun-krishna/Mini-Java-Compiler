import syntaxtree.*;
import visitor.*;
import java.util.*;

public class P2 {
   public static void main(String [] args) {
      try {
         Node root = new MiniJavaParser(System.in).Goal();
         
         HashMap<String,HashMap<String,String>> classVariables = new HashMap<String,HashMap<String,String>>(); // Store class Variables
         HashMap<String,HashMap<String,HashMap<String,String>>> classMethods = new HashMap<String,HashMap<String,HashMap<String,String>>>();   // Store class Methods
         List<String []> classRelation = new ArrayList<String []>();           // Store class relations
         List<String>declaredClasses = new ArrayList<String>();
         List<String> basicTypes = new ArrayList<String>();
         basicTypes.add("int");
         basicTypes.add("int[]");
         basicTypes.add("boolean");
         root.accept( new GJNoArguDepthFirst<String>(classVariables,classMethods,classRelation,basicTypes,declaredClasses));

         // System.err.println("First Pass Data : ");
         // System.err.println("classVariables : ");
         // System.err.println(classVariables);
         // System.err.println(" ----- ");
         // System.err.println("classMethods : ");
         // System.err.println(classMethods);
         // System.err.println(" ----- ");
         // System.err.println("declaredClasses : ");
         // System.err.println(declaredClasses);
         // System.err.println(" ----- ");
         
         //root.accept( new GJDepthFirst<String,String>(classVariables,classMethods,classRelation,basicTypes,declaredClasses) , null); // Your assignment part is invoked here.
         System.out.println("Program type checked successfully");
      }
      catch (ParseException e) {
         System.out.println("Type error");
      }
   }
}
