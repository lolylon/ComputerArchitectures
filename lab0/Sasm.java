import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Sasm {
    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(new File(args[0])); // "numsum.sa"
        int linenum = 0;
        HashMap<String,String> labels = new HashMap<>();
        ArrayList<String> operations =new ArrayList<>();
        // first pass
        while (input.hasNextLine()){
            String line = input.nextLine();
            String [] s = line.split(":");
            if (s.length==2){
                labels.put(s[0].trim(),String.format("%02d",linenum));
//                System.out.printf("%02d %s\n",linenum,s[1].trim());
                operations.add(linenum,s[1].trim());
            } else {
//                System.out.printf("%02d %s\n",linenum,s[0].trim());
                operations.add(linenum,s[0].trim());
            }
            linenum++;
        }

        HashMap<String, String> commandCode = new HashMap<>();
        commandCode.put("READ","10");
        commandCode.put("WRITE","11");
        commandCode.put("LOAD","20");
        commandCode.put("STORE","21");
        commandCode.put("ADD","30");
        commandCode.put("SUBTRACT","31");
        commandCode.put("DIVIDE","32");
        commandCode.put("MULTIPLY","33");
        commandCode.put("BRANCH","40");
        commandCode.put("BRANCHNEG","41");
        commandCode.put("BRANCHZERO","42");
        commandCode.put("HALT","43");


        for(String line:operations) {
            String s[] = line.trim().split(" ");
            String opcode = commandCode.get(s[0].trim());
            String word = "";
            if (opcode==null) word = String.format("%04d", Integer.parseInt( s[0].trim()));
            else {
                String operand = "00";
                if (s.length>1) operand = labels.get(s[1].trim());
                word = opcode + operand;
            }
            System.out.println(word);
        }
//        System.out.println(operations);
//        System.out.println(labels);
    }
}
