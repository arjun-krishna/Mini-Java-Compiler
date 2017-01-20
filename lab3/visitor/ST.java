package visitor;
import java.util.*;

public class ST {
	public HashMap<String,List<String[]>> functionMap;
	public HashMap<String,List<String[]>> variableMap;
	public HashMap<String,HashMap<String,HashMap<String,String>>> funcData;
	public List<String[]> classRelation;
	public HashMap<String,ClassObject> hm;


	public ST() {
		functionMap = new HashMap<String,List<String[]>>();
		variableMap = new HashMap<String,List<String[]>>();
		funcData = new HashMap<String,HashMap<String,HashMap<String,String>>>();
		classRelation = new ArrayList<String[]>();
	}
	
	public void make() {
		hm = obtainStructs(classRelation,functionMap,variableMap);
	}

	HashMap<String,ClassObject> obtainStructs(List<String[]> classRelation,HashMap<String,List <String[]>> functionMap,HashMap<String,List <String[]>> variableMap) {
      
      // Obtains the VTable and the data of a class, used for conversion

      HashMap<String,ClassObject> hm = new HashMap<String,ClassObject>();
      List<Boolean> done = new ArrayList<Boolean>();  // INDICATES when a classObject is done

      for (int i = 0; i < classRelation.size(); i++) { // INITIALIZE CLASS OBJECTS
         String[] t = classRelation.get(i);
         ClassObject obj = new ClassObject();
         hm.put(t[0],obj);
         done.add(false);
      } 

      for (int i = 0; i< classRelation.size(); i++) {
         obtain(i,hm,done,classRelation,functionMap,variableMap);
      }
      return hm;
   }

   ClassObject obtain(int i,HashMap<String,ClassObject> hm,List<Boolean> done,List<String[]> classRelation,HashMap<String,List <String[]>> functionMap,HashMap<String,List <String[]>> variableMap) {
      
      // Recursively called to ensure each class has it's mapping to classObject setup

      if ( done.get(i)) {
         return hm.get(classRelation.get(i)[0]);
      }
      else {
         if ( classRelation.get(i)[1] == null) { // LONE CLASS 
            String className = classRelation.get(i)[0]; 
            ClassObject obj = new ClassObject();
            List<String[]> vars = variableMap.get(className);
            List<String[]> funcs = functionMap.get(className);
            for(int j = 0; j < vars.size(); j++) {
               obj.addVariable(vars.get(j)[0], className);
            }
            for(int j = 0; j < funcs.size(); j++) {
               obj.addFunction(funcs.get(j)[0], className);
            }
            done.set(i,true);
            hm.put(className,obj);
            return obj;
         } 
         else {   // Has a parent class
            int p = getIndexOfParent(i,classRelation);
            ClassObject parent = obtain(p,hm,done,classRelation,functionMap,variableMap); 
            ClassObject obj = new ClassObject();
            for (int j = 0; j < parent.VTable.size(); j++) {
               obj.VTable.add(parent.VTable.get(j));
            }
            for (int j = 0;j < parent.data.size(); j++) {
               obj.data.add(parent.data.get(j));
            }
            String className = classRelation.get(i)[0]; 
            List<String[]> vars = variableMap.get(className);
            List<String[]> funcs = functionMap.get(className);
            for(int j = 0; j < vars.size(); j++) {
               obj.addVariable(vars.get(j)[0], className);
            }
            for(int j = 0; j < funcs.size(); j++) {
               obj.addFunction(funcs.get(j)[0], className);
            }
            done.set(i,true);
            hm.put(className,obj);
            return obj;
         }
      }
   }
   int getIndexOfParent(int i, List<String[]> classRelation) {
      String parent = classRelation.get(i)[1];
      for(int j = 0; j < classRelation.size(); j++) {
         if(parent.equals(classRelation.get(j)[0]))
            return j;
      }
      // some type check error! Then comes here!
      System.exit(0); 
      return -1;
   }

   public void debug() {
      Iterator it = hm.entrySet().iterator();
      while (it.hasNext()) {
        Map.Entry pair = (Map.Entry)it.next();
        System.out.println("Class : "+pair.getKey()); // + " = " + pair.getValue());
        ClassObject obj = hm.get(pair.getKey());
        obj.print();
        System.out.println(" ------------------- ");
      }
   }
}



   

   