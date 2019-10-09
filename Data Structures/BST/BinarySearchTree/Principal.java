import java.io.*;

public class Principal {

	public static void main(String[] args) {
		ABB arvore = new ABB();
		// Inserindo os elementos da ABB a partir do arquivo
		try {
			FileReader file = new FileReader("arvore.txt");
			BufferedReader br = new BufferedReader(file);
			String linha = br.readLine();
			while (linha != null) {
				String[] separado = linha.split(" ");
				for (String a : separado) {
					arvore.inserir(arvore.raiz, Integer.parseInt(a));
				}

				linha = br.readLine();
			}
			br.close();
		} catch (IOException e) {
			System.err.println("Erro de abertura no arquivo");
		}
		try {
			FileReader file = new FileReader("operacoes.txt");
			BufferedReader br = new BufferedReader(file);
			String linha = br.readLine();
			while (linha != null) {
				String[] separado = linha.split(" ");
				// Assumindo que o arquivo está organizado corretamente
				int valor = 0;
				String metodo = separado[0];
				if (separado.length > 1) {
					valor = Integer.parseInt(separado[1]);
				}
				// Chamando os metodos
				if (metodo.equals("INSIRA")) {
					arvore.inserir(arvore.raiz, valor);
				}
				if (metodo.equals("REMOVA")) {
					arvore.remover(arvore.raiz, valor);
				}
				if (metodo.equals("CHEIA")) {
					System.out.println("Cheia: " + arvore.ehCheia(arvore.raiz));
				}
				if (metodo.equals("COMPLETA")) {
				//	arvore.inserir(arvore.raiz, valor);
				}
				if (metodo.equals("BUSCAR")) {
					arvore.buscar(valor, arvore.raiz);
				}
				if (metodo.equals("ENESIMO")) {
					if (arvore.enesimoElemento(arvore.raiz, valor) != null) {
						System.out.println("Elemento: " + arvore.enesimoElemento(arvore.raiz, valor).valor);
					} else {
						System.out.println("A ABB não comporta esse n-ésimo elemento");
					}
				}
				if (metodo.equals("POSICAO")) {
					if (arvore.posicao(arvore.raiz, valor) == -1) {
						System.out.println("O valor não está nna ABB");
					} else {
						System.out.println("Posição: " + arvore.posicao(arvore.raiz, valor));
					}
				}
				if (metodo.equals("IMPRIMA")) {
					System.out.println("To string: " + arvore.toString(arvore.raiz));
				}
				if (metodo.equals("MEDIANA")) {
					System.out.println("Mediana: " + arvore.mediana(arvore.raiz).valor);
				}
				linha = br.readLine();
			}
			br.close();
		} catch (IOException e) {
			System.err.println("Erro de abertura no arquivo");
		}
	}
}
