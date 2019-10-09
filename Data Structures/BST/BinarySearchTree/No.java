
public class No {
	public No direita;
	public No esquerda;
	public int valor;
	public int qnt_sub_esq;
	public int qnt_sub_dir;

	public No() {
		this.direita = null;
		this.esquerda = null;
		// TODO Auto-generated constructor stub
	}

	public No(int valor) {
		this.valor = valor;
		this.direita = null;
		this.esquerda = null;
		this.qnt_sub_esq = 0;
		this.qnt_sub_dir = 0;
	}

	public void aumentaSubEsq() {
		this.qnt_sub_esq = this.qnt_sub_esq + 1;
	}

	public void aumentaSubDir() {
		this.qnt_sub_dir = this.qnt_sub_dir + 1;
	}
}
