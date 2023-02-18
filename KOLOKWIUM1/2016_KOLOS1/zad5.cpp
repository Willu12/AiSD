/*4. B*-drzewa to pewna modyfikacja B-drzew.
a) Napisz funkcję ConvertAndDelete która konwertuje B* drzewo rzędu m do B-drzewa rzędu m a
następnie zaraz po konwersji usuwa medianę korzenia (przy parzystej liczbie elementów w
korzeniu usuwa dowolny z dwóch elementów środkowych).
b) Narysuj końcowe B-drzewo rzędu 1 oraz kolejne etapy w czasie wstawiania pierwszych 9
unikalnych liter nazwiska + imienia.
c) Jaka jest praktyczna złożoność czasowa operacji wyszukiwania w B-drzewach i jak ją się określa?*/

#define m 512


struct node
{
    int keys[2*m + 1]; //indeksujemy od 1 keys[0] wartownik
    node* next[2*m + 1];
    int k; // m<=k<=2m;

}*root;
int ConvertAndDelete(node * root)
{
    // nie trzeba nic konwertowac bo B* drzewa spelnia zalozenia B-drzewa

    int mediana = root->keys[root->k/2];
    node * p = root->next[(root->k)/2 + 1]; //bierzemy strone elemtu za mediana i szukamy w niej min elementu

    //gdy jest tlyko jedna strona nie
    if(!p)
    {
        for(int i = (root->k /2); i<root->k -1 ; i++)
        {
            root->keys[i] = root->keys[i+1];
        }
        root->k--;
        return;
    }

    //schodzimy na sam dol
    while(p->next[0])
    {
        p = p->next[0];
    }
    root->keys[root->k/2] = p->keys[0];
    //przesuwamy wszystkie elemtyu w na silsice
    for(int i =0; i<p->k -1 ; i++)
    {
        p->keys[i] = p->keys[i + 1];
    }
    p->k--;
    return mediana;
}


//ROWNOWAZENIE STRONY W BDRZEWIE RZEDU 1 
//Rownowazanie zachodzi gdy chcmey usunac element ze sotrny ktora ma k = m elementow
// wtedy nalezy poprzesuwac elemty ze strony po lewej lub po prawo tak aby oby dwie byly rowne

void balance(int i , node* parent) // i - numer strony z tablicy parent->next[i] - strona ktora chcemy xzbasalnowac
{
    //jestesmy po usunieciu elementu i nasza strona ma m-1 elementow
    if(parent->next[i + 1]->k > m) //prawa strona ma podan m elementow
    {
        node * p = parent->next[i];
        node * right = parent->next[i + 1];
        int j =0;
        while(p->k /2 != right->k /2)
        {
            //1. do p wstawaimty z rodzica 
            // do rodzica z right
            p->keys[p->k + 1] = parent->keys[i];
            parent->keys[i] = right->keys[j++];
            p->k++;
            right->k--;
        }
        //przesuniece elmetow z prawej strony
        for(int in =0; in<right->k; in++)
        {
            right->keys[in] = right->keys[in + j];
        }

    } 

    
}