
                int index=getfree(parkinglot);
                if (index>-1){
                    parkinglot[index].fillspace(1);
                }
                else {
                    cout<<"parking not free"<<endl;
                }
                break;