fun sort(data: Array<Int>): Array<Int> {
    // Ignore null checks since the array will not be empty
    val min = data.min()!!
    val size = data.max()!! - min + 1
    val holes = IntArray(size)
    for (it in data)
        holes[it - min]++

    var i = 0
    for (count in 0 until size)
        while (holes[count] > 0){
            holes[count]--
            data[i] = count + min
            i++
        }

    return data
}
