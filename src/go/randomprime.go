package main

import (
	"crypto/rand"
	"fmt"
	"math/big"
)

var ZERO *big.Int = big.NewInt(0)
var ONE *big.Int = big.NewInt(1)
var TWO *big.Int = big.NewInt(2)
var THREE *big.Int = big.NewInt(3)

// Miller-Rabian Primality Test
func isPrime(val *big.Int) bool {

	var temp *big.Int = new(big.Int)
	var valSub1 *big.Int = new(big.Int).Set(val)
	valSub1.Sub(valSub1, ONE)
	var oddTester *big.Int = new(big.Int).Set(valSub1)

	if ZERO.Cmp(val) == 0 || ONE.Cmp(val) == 0 {
		return false
	}

	if TWO.Cmp(val) == 0 || THREE.Cmp(val) == 0 {
		return true
	}

	var numDivisions int64 = 0
	for temp.Mod(oddTester, TWO).Cmp(ZERO) == 0 {
		oddTester.Rsh(oddTester, 1)
		numDivisions++
	}

	max_size := new(big.Int)
	temp = big.NewInt(int64(temp.Set(valSub1).BitLen()))
	max_size.Exp(TWO, temp, nil).Sub(max_size, ONE)

	for i := 0; i < 100; i++ {
		var witness *big.Int
		for {
			witness, _ = rand.Int(rand.Reader, max_size)
			if witness.Cmp(TWO) > 0 && witness.Cmp(valSub1) < 0 {
				break
			}
		}
		modPowTest := new(big.Int).Set(witness)
		modPowTest.Exp(modPowTest, oddTester, val)
		if modPowTest.Cmp(ONE) == 0 || modPowTest.Cmp(valSub1) == 0 {
			continue
		}

		var i int64 = 0
		for ; i < numDivisions; i++ {
			modPowTest.Exp(modPowTest, TWO, val)
			if modPowTest.Cmp(ONE) == 0 {
				return false
			}
			if modPowTest.Cmp(valSub1) == 0 {
				break
			}
		}

		if i == numDivisions {
			return false
		}
	}
	return true
}

func GenPrime(bitSize int64) *big.Int {
	max_size := new(big.Int)
	max_size.Exp(TWO, big.NewInt(bitSize), nil).Sub(max_size, ONE)
	for {
		n, _ := rand.Int(rand.Reader, max_size)
		if isPrime(n) {
			return n
		}
	}
}

func main() {
	p := GenPrime(20)
	fmt.Println(p.String())
}
