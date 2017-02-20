/**
 *
 */


// http://stackoverflow.com/questions/2283494/get-ip-address-of-an-interface-on-linux
// http://stackoverflow.com/questions/20800319/how-do-i-get-my-ip-address-in-c-on-linux
char *
get_public_ip()
{
    system("dig +short myip.opendns.com @resolver1.opendns.com");
    system("dig +short o-o.myaddr.l.google.com @ns1.google.com -t txt | sed \'s/\"//g\'");
    return NULL;
}



char *
get_private_ip()
{
    system("hostname -I");
    return NULL;
}


