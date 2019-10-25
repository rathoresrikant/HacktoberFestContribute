fun sort(data: Array<Int>): Array<Int> {
    var pos = 0
    while (pos < data.size) {
        if (pos == 0 || data[pos] >= data[pos-1]) {
            pos += 1
        } else {
            val j = data[pos]
            data[pos] = data[pos-1]
            data[pos-1] = j
            pos -= 1
        }
    }
    return data
}
