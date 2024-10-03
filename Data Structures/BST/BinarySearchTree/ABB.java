import java.util.Queue;
import java.util.Stack;
import java.util.LinkedList;

public class ABB {
	public No raiz;

	public ABB() {
		this.raiz = null;
	}

	public ABB(No n) {
		// Criando uma árvore binária já com uma raiz
		this.raiz = n;
	}

	public No elementoBilbo(No raiz) {
		// Elemento Bilbo é o nome criado por mim caracterizado por ser o nó mais a
		// direita, ou seja, o de maior valor
		if (raiz.direita == null) {
			return raiz;
		} else {
			return elementoBilbo(raiz.direita);
		}
	}

	public No remover(No raiz, int valor) {
		if (raiz == null) {

			// Não faça nada, pois se não achou o valor até agora, não é em um nó nulo que
			// vai achar :)
			return null;
		}
		if (raiz.valor > valor) {
			// Como a raiz é maior, procure na esquerda
			raiz.esquerda = remover(raiz.esquerda, valor);
		}
		if (raiz.valor < valor) {
			// Como a raiz é menor que o valor, procure na direita
			raiz.direita = remover(raiz.direita, valor);
		}
		if (raiz.valor == valor) {
			// Achamos o caboclo que queremos remover...
			if (raiz.direita == null) {
				// Se ele não tem direita, ele tem esquerda, logo retorne-a!
				return raiz.esquerda;
			} else if (raiz.esquerda == null) {
				// Se ele não tem esquerda, ele tem direita, logo retorne-a
				return raiz.direita;
			}
			// Se o algoritmo chegou até aqui, então o alvo tem dois filhos. Então substitua
			// o elemento mais a direita da sub-árvore à esquerda
			// E chame remova esse valor encontrado
			raiz.valor = elementoBilbo(raiz.esquerda).valor;
			raiz.esquerda = remover(raiz.esquerda, raiz.valor);

		}
		return raiz;
	}

	public void inserir(No raiz, int valor) {
		if (raiz == null) {
			// Para não dar erro caso caia em um nó nulo
			this.raiz = new No(valor);
			return;
		}
		if (raiz.valor == valor) {
			// Não faça nada, ele já está na arvore!
			System.out.println("Tentou adicionar " + valor + ". Não faça nada, ele já está na arvore!");
			return;
		}
		if (raiz.valor > valor) {
			// Inserir na esquerda da subarvore
			if (raiz.esquerda == null) {
				raiz.esquerda = new No(valor);
			} else {
				inserir(raiz.esquerda, valor);
			}
		}
		if (raiz.valor < valor) {
			// Inserir na direita da sub-arvore
			if (raiz.direita == null) {
				raiz.direita = new No(valor);
			} else {
				inserir(raiz.direita, valor);
			}

		}
	}

	public void inOrder(No raiz) {
		if (raiz != null) {
			inOrder(raiz.esquerda);
			System.out.print(raiz.valor + " ");
			inOrder(raiz.direita);
		}
	}

	public boolean buscar(int valor, No raiz) {
		if (raiz == null) {
			// Para não dar erro caso caia em um nó nulo
			return false;
		}
		if (raiz.valor == valor) {
			return true;
		}
		if (raiz.valor > valor) {
			// Se o valor for menor é lógico que está na sub-árvore à esquerda
			return buscar(valor, raiz.esquerda);
		} else {
			// Se o valor for maior é lógico que está na sub-árvore à direita
			return buscar(valor, raiz.direita);
		}
	}

	public String toString(No raiz) {
		Queue<No> fila = new LinkedList<No>(); // Inicialização padrão de uma fila de "nós
		String resposta = ""; // Adicionando a string que será utilizada para retornar os valores dos elementos
		fila.add(raiz);
		while (fila.isEmpty() != true) {
			No aux = fila.peek();
			fila.remove(aux);
			resposta += aux.valor + " ";
			if (aux.esquerda != null) {
				fila.add(aux.esquerda);
			}
			if (aux.direita != null) {
				fila.add(aux.direita);
			}
		}
		return resposta;
	}

	public int tamanhoArvore(No raiz) {
		if (raiz == null) {
			// Chegou na folha
			return 0;
		} else {
			int altura_esq = tamanhoArvore(raiz.esquerda);
			int altura_dir = tamanhoArvore(raiz.direita);
			return Math.max(altura_esq, altura_dir) + 1;
		}
	}

	public No enesimoElemento(No raiz, int elemento) {
		Stack<No> stack = new Stack<No>();
		int cont = 1;
		while (!stack.empty() || raiz != null) {
			if (raiz == null) {
				raiz = stack.pop();
				if (cont == elemento) {
					return raiz;
				}
				cont++;
				raiz = raiz.direita;
			} else {
				stack.push(raiz);
				raiz = raiz.esquerda;
			}
		}
		return null;
	}

	public int quantidadeElementos(No raiz) {
		if (raiz == null) {
			return 0;
		}
		return 1 + quantidadeElementos(raiz.esquerda) + quantidadeElementos(raiz.direita);
	}

	public No mediana(No raiz) {
		int elementos = quantidadeElementos(raiz);
		if (elementos % 2 != 0) {
			elementos++;
		}
		int mediana = elementos / 2;
		return enesimoElemento(raiz, mediana);
	}

	public int posicao(No raiz, int valor) {
		Stack<No> stack = new Stack<No>();
		int cont = 1;
		while (!stack.empty() || raiz != null) {
			if (raiz == null) {
				raiz = stack.pop();
				if (raiz.valor == valor) {
					return cont;
				}
				cont++;

				raiz = raiz.direita;
			} else {
				stack.push(raiz);
				raiz = raiz.esquerda;
			}
		}
		return -1;
	}

	public boolean ehCheia(No raiz) {
		if (raiz == null || (raiz.direita == null && raiz.esquerda == null)) {
			// Para caso a raiz seja nula ou tivermos chegado em uma folha
			return true;
		}
		if (raiz.esquerda != null) {
			if (raiz.direita != null) {
				// a arvore continua
				return (this.ehCheia(raiz.esquerda) && this.ehCheia(raiz.direita));
			}
		}
		return false;
	}
}
