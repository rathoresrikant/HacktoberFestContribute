bool checkValidity(queue<int> q)
{
    if(q.size() ==0)
        return true;
    int past = q.front();
    q.pop();
    bool test = false;
    while(q.front() != q.back()){ //past is the value prior to top of queue
        if(past<=q.front())
            test = true;
        else
            test = false;
        past = q.front();
        q.pop();
    }
    if(past<=q.front())
        test = true;
    else
        test = false;
    return test;
}