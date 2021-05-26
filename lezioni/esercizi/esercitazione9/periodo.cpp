int List_int::periodo(){
    int k=0;
    Cella* pc = l;
    int testa = pc->info;
    int temp=0;
    if(pc){
        pc = pc ->next;
        temp = pc->info;
        k++;
        while(temp != testa){
            if(pc->next==nullptr){
                temp = testa;
                k++;
            }else{

            k++;
            pc = pc ->next;
            temp = pc->info;
            }
        }

        return k;
    }else{

        return k;
    }
}