#include <stdio.h>
char PHE[2][4] = {"UUC","UUU"};
char LEU[6][4] = {"UUA","UUG","CUU","CUC","CUA","CUG"};
char ILE[3][4] = {"AUU","AUC","AUA"};
char MET[1][4] = {"AUG"};
char VAL[4][4] = {"GUU","GUC","GUA","GUG"};
char SER[6][4] = {"UCU","UCC","UCA","UCG","AGU","AGC"};
char PRO[4][4] = {"CCU","CCC","CCA","CCG"};
char THR[4][4] = {"ACU","ACC","ACA","ACG"};
char ALA[4][4] = {"GCU","GCC","GCA","GCG"};
char TYR[2][4] = {"UAU","UAC"};
char CYS[2][4] = {"UGU","UGC"};
char stop[3][4] = {"UAA","UAG","UGA"};
char HIS[2][4] = {"CAU","CAC"};
char GLN[2][4] = {"CAA","CAG"};
char ASN[2][4] = {"AAU","AAC"};
char LYS[2][4] = {"AAA","AAG"};
char ASP[2][4] = {"GAU","GAC"};
char GLU[2][4] = {"GAA","GAG"};
char ARG[6][4] = {"CGU","CGC","CGA","CGG","AGA","AGG"};
char TRP[1][4] = {"UGG"};
char GLY[4][4] = {"GGU","GGC","GGA","GGG"};
/* Convert DNA to mRNA */
char converter(char nukleotid)
{
    switch (nukleotid)
    {
    case 'A':
        return 'U';
        break;
    case 'T':
        return 'A';
        break;
    case 'G':
        return 'C';
        break;
    case 'C':
        return 'G';
        break;
    default:
        return '\0';
        break;
    }
}
/* String equality */
int is_equal(char str1[4],char str2[4])
{
    int i;
    for (i = 0; i < 4; i++)
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }
    }
    return 1;
}
/* Codon - Protein check */
int check_codon(char protein,char codon[4])
{
    int i;
    switch (protein)
    {
        case 'z':
            /* stop */
            for (i = 0; i < 3; i++)
            {
                if (is_equal(stop[i],codon))
                {
                    return 1;
                }
            }
            return 0;
            break;
        case 'g':
            /* GLY */
            for (i = 0; i < 4; i++)
            {
                if (is_equal(GLY[i],codon))
                {
                    return 1;
                }
            }
            return 0;
            break;
        case 'a':
            /* ALA */
            for (i = 0; i < 4; i++)
            {
                if (is_equal(ALA[i],codon))
                {
                    return 1;
                }
            }
            return 0;
            break;
        case 'v':
            /* VAL */
            for (i = 0; i < 4; i++)
            {
                if (is_equal(VAL[i],codon))
                {
                    return 1;
                }
            }
            return 0;
            break;
        case 'i':
            /* ILE */
            for (i = 0; i < 3; i++)
            {
                if (is_equal(ILE[i],codon))
                {
                    return 1;
                }
            }
            return 0;
            break;
        case 'l':
            /* LEU */
            for (i = 0; i < 6; i++)
            {
                if (is_equal(LEU[i],codon))
                {
                    return 1;
                }
            }
            return 0;
            break;
        case 's':
            /* SER */
            for (i = 0; i < 6; i++)
            {
                if (is_equal(SER[i],codon))
                {
                    return 1;
                }
            }
            return 0;
            break;
        case 't':
            /* THR */
            for (i = 0; i < 4; i++)
            {
                if (is_equal(THR[i],codon))
                {
                    return 1;
                }
            }
            return 0;
            break;
        case 'p':
            /* PRO */
            for (i = 0; i < 4; i++)
            {
                if (is_equal(PRO[i],codon))
                {
                    return 1;
                }
            }
            return 0;
            break;
        case 'd':
            /* ASP */
            for (i = 0; i < 2; i++)
            {
                if (is_equal(ASP[i],codon))
                {
                    return 1;
                }
            }
            return 0;
            break;
        case 'e':
            /* GLU */
            for (i = 0; i < 2; i++)
            {
                if (is_equal(GLU[i],codon))
                {
                    return 1;
                }
            }
            return 0;
            break;
        case 'k':
            /* LYS */
            for (i = 0; i < 2; i++)
            {
                if (is_equal(LYS[i],codon))
                {
                    return 1;
                }
            }
            return 0;
            break;
        case 'r':
            /* ARG */
            for (i = 0; i < 6; i++)
            {
                if (is_equal(ARG[i],codon))
                {
                    return 1;
                }
            }
            return 0;
            break;
        case 'n':
            /* ASN */
            for (i = 0; i < 2; i++)
            {
                if (is_equal(ASN[i],codon))
                {
                    return 1;
                }
            }
            return 0;
            break;
        case 'q':
            /* GLN */
            for (i = 0; i < 2; i++)
            {
                if (is_equal(GLN[i],codon))
                {
                    return 1;
                }
            }
            return 0;
            break;
        case 'c':
            /* CYS */
            for (i = 0; i < 2; i++)
            {
                if (is_equal(CYS[i],codon))
                {
                    return 1;
                }
            }
            return 0;
            break;
        case 'm':
            /* MET */
            for (i = 0; i < 1; i++)
            {
                if (is_equal(MET[i],codon))
                {
                    return 1;
                }
            }
            return 0;
            break;
        case 'w':
            /* TRP */
            for (i = 0; i < 1; i++)
            {
                if (is_equal(TRP[i],codon))
                {
                    return 1;
                }
            }
            return 0;
            break;
        case 'f':
            /* PHE */
            for (i = 0; i < 2; i++)
            {
                if (is_equal(PHE[i],codon))
                {
                    return 1;
                }
            }
            return 0;
            break;
        case 'y':
            /* TYR */
            for (i = 0; i < 2; i++)
            {
                if (is_equal(TYR[i],codon))
                {
                    return 1;
                }
            }
            return 0;
            break;
        case 'h':
            /* HIS */
            for (i = 0; i < 2; i++)
            {
                if (is_equal(HIS[i],codon))
                {
                    return 1;
                }
            }
            return 0;
            break;
    default:
        return 0;
        break;
    }
}
int main(void){
    char sequence[3000];
    char protein[2900];
    int seq_counter = 0;
    int protein_counter = 0;
    char mycodon[4];
    int seq_cursor = 0;
    int protein_cursor = -1;
    int start1,end1=0,start2=0,end2;
    int midpoint1,midpoint2;
    char mychar;
    mycodon[3] = '\0';
    /* Get Inputs*/
    while ((mychar = getchar())!='.')
    {
        if (mychar != '\n' && mychar != ' ')
        {
            sequence[seq_counter++] = converter(mychar);
        }
    }
    sequence[seq_counter] = '\0';
    while ((mychar = getchar())!='.')
    {
        if (mychar != '\n' && mychar != ' ')
        {
            protein[protein_counter++] = mychar;
        }
    }
    protein[protein_counter++] = 'z';
    protein[protein_counter] = '\0';
    /* Get First intron start point*/
    do
    {
        int i;
        for (i = 0; i < 3; i++)
        {
            mycodon[i] = sequence[seq_cursor++];
        }
        protein_cursor++;
    } while (protein_cursor<protein_counter-2 && check_codon(protein[protein_cursor],mycodon));
    start1 = seq_cursor-3;
    midpoint1 = protein_cursor;
    protein_cursor = protein_counter;
    seq_cursor = seq_counter-1;
    /* Get Second intron end point */
    do
    {
        int i;
        for (i = 2; i > -1; i--)
        {
            mycodon[i] = sequence[seq_cursor--];
        }
        protein_cursor--;
    } while (protein_cursor>1  && check_codon(protein[protein_cursor],mycodon));
    end2 = seq_cursor+3;
    midpoint2 = protein_cursor;
    if (start1 <= 0 || end2 >= seq_counter-1)
    {
        printf("NONE");
        return 0;
    }
    /* Check For Overlapping (align midpoints)*/
    if (midpoint1>midpoint2)
    {
        int temp_mp;
        for (temp_mp = midpoint2; temp_mp <= midpoint1; temp_mp++)
        {
            int temp_seq = start1+1;
            int sub2 = temp_mp-midpoint2;
            int sub1 = midpoint1-temp_mp;
            while (temp_seq<end2-2)
            {
                int i;
                for (i = 0; i < 3; i++)
                {
                    mycodon[i] = sequence[temp_seq++];
                }
                if (check_codon(protein[temp_mp],mycodon))
                {
                    end2 += sub2*3;
                    midpoint2 += sub2;
                    start1 -= sub1*3;
                    midpoint1 -= sub1;
                    temp_seq -= 3;
                    break;
                }
                temp_seq -= 2;
            }
            if (temp_seq<end2-2)
            {
                break;
            }
        }
    }
    /* Look for mid exon */
    seq_cursor = start1+1;
    protein_cursor = midpoint1;
    while (seq_cursor<end2-2)
    {
        int i;
        for (i = 0; i < 3; i++)
        {
            mycodon[i] = sequence[seq_cursor++];
        }
        if (check_codon(protein[protein_cursor],mycodon))
        {
            int sub = midpoint2-midpoint1;
            int temp_seq = seq_cursor;
            int i;
            for (i = midpoint1+1; i <= midpoint2; i++)
            {
                int k;
                for (k = 0; k < 3; k++)
                {
                    mycodon[k] = sequence[temp_seq++];
                }
                if (!check_codon(protein[i],mycodon))
                {
                    break;
                }
            }
            if(i > midpoint2)
                {
                    start2 = temp_seq;
                    end1 = start2 - (sub+1)*3-1;
                    seq_cursor -= 3;
                    break;
                }
        }
        seq_cursor -= 2;
    }
    if (seq_cursor>=end2-2 || start1 > end1 || end1 > start2 || start2 > end2)
    {
        printf("NONE");
    }
    else{
        printf("%d %d %d %d",start1,end1,start2,end2);
    }
    return 0;
}
