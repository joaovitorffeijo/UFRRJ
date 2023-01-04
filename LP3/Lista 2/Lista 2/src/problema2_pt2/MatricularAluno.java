package problema2_pt2;

import java.util.HashMap;
import java.util.Scanner;
import java.util.ArrayList;

public class MatricularAluno {

	static HashMap<Long, ArrayList<String>> alunos = new HashMap<Long, ArrayList<String>>();
	
	public static void matricula() {
		
		Scanner scan = new Scanner(System.in);
		
		Long matricula;
		// Matricula foi declarado como Long porque um Integer só vai até 2147483647 e as matriculas
		// são maiores que este valor, que é o máximo.

		String turma;
		
		while(true) {
			System.out.println("Nova matrícula ou existente: ");
			matricula = scan.nextLong();
			
			if(matricula < 0) {break;}
			else {
				System.out.println("Nova turma: ");
				turma = scan.next();
				
				if(alunos.containsKey(matricula)) {
					alunos.get(matricula).add(turma);
				}
				else {
					alunos.put(matricula, new ArrayList<>());
					alunos.get(matricula).add(turma);
				}
			}
		}

		for(Long i : alunos.keySet()) {
			for(String j : alunos.get(i)) {
				System.out.println(i + " " + j);
			}
		}

		scan.close();
	}
}