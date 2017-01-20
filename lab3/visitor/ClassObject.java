package visitor;
import java.util.*;

public class ClassObject {
	public List <String> VTable;	// stores A~foo
	public List <String> data;		// stores A~f1   ( A_f1 )

	public ClassObject () {
		VTable = new ArrayList<String>();
		data = new ArrayList<String>();
	}

	public void addFunction(String functionName,String className) {
		for (int i = 0; i < VTable.size() ; i++) {
			String temp = VTable.get(i);
			String[] splits = temp.split("~");
			temp = splits[1];
			if (temp.equals(functionName)) {
				VTable.set(i,className+"~"+functionName);
				return;
			}
		}
		VTable.add(className+"~"+functionName);
	}

	public void addVariable(String v,String className) {
		data.add(className+"~"+v);
	}

	public void print() {
		System.out.println("Functions");
		for (int i = 0; i < VTable.size() ; i++) {
			System.out.println(i+" --> "+VTable.get(i));
		}
		System.out.println("Data");
		for (int i = 0; i< data.size() ; i++) {
			System.out.println(i+" --> "+data.get(i));
		}
	}
}