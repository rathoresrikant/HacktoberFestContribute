def run_rc4(text,key):
    resultado = []
    for char in text:
        resultado.append(rc4(char,key))
    
    return bytearray(resultado)



def rc4(value,key):
  SJ = KSA(key)
  generatedByte = GenFluxo(SJ[0])
  return value ^ next(generatedByte)


def KSA(key):
    S = []
    T = []
    for i in range(256):
        S.append(i)
        T.append(i % key)

    j = 0

    for i in range(256):
        j = (j + S[i] + T[i]) % 256
        swap(S,i,j)

    return (S,T)


def GenFluxo(S):
    i = 0
    j = 0

    while(True):
        i = (i+1) % 256
        j = (j + S[i]) % 256
        swap(S,i,j)
        K = S[(S[i] + S[j]) % 256]
        yield K
        
def swap(lista,index1,index2):
    tmp = lista[index1]
    lista[index1] = lista[index2]
    lista[index1] = tmp

if __name__ == "__main__":
    input_val = bytearray("encrypted text","utf-8")
    print(run_rc4(input_val,4))
    print(run_rc4(run_rc4(input_val,4),4).decode("utf-8"))
