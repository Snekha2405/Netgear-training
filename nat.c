#include <stdio.h>
#include <string.h>

#define MAX_NAT 10
#define IP_LEN 16

#define TCP 6
#define UDP 17

/* ---------- GLOBAL PUBLIC IP ---------- */
char PUBLIC_IP[IP_LEN] = "203.0.113.1";

/* ---------- NAT ENTRY ---------- */
typedef struct {
    char private_ip[IP_LEN];
    int  private_port;

    int  public_port;

    char dest_ip[IP_LEN];
    int  dest_port;

    int protocol;
} NAT;

/* ---------- NAT TABLE ---------- */
NAT table[MAX_NAT];
int nat_count = 0;
int next_public_port = 40000;

/* ---------- OUTBOUND ---------- */
int nat_outbound(char *priv_ip, int priv_port,
                 char *dest_ip, int dest_port,
                 int proto,
                 int *pub_port)
{
    NAT *e = &table[nat_count++];

    strcpy(e->private_ip, priv_ip);
    strcpy(e->dest_ip, dest_ip);

    e->private_port = priv_port;
    e->dest_port = dest_port;
    e->public_port = next_public_port++;
    e->protocol = proto;

    *pub_port = e->public_port;
    return 0;
}

/* ---------- INBOUND ---------- */
int nat_inbound(int pub_port,
                char *src_ip, int src_port,
                int proto,
                char *priv_ip, int *priv_port)
{
    for (int i = 0; i < nat_count; i++) {
        if (table[i].public_port == pub_port &&
            strcmp(table[i].dest_ip, src_ip) == 0 &&
            table[i].dest_port == src_port &&
            table[i].protocol == proto) {

            strcpy(priv_ip, table[i].private_ip);
            *priv_port = table[i].private_port;
            return 0;
        }
    }
    return -1;
}

/* ---------- MAIN ---------- */
int main() {
    char *priv_ip[5] = {
        "10.0.0.2", "10.0.0.3", "10.0.0.4",
        "10.0.0.5", "10.0.0.6"
    };

    int priv_port[5] = {1111, 2222, 3333, 4444, 5555};

    char *dest_ip[5] = {
        "8.8.8.8", "1.1.1.1", "93.184.216.34",
        "142.250.4.100", "52.94.236.248"
    };

    int dest_port[5] = {53, 53, 80, 443, 443};
    int proto[5] = {UDP, UDP, TCP, TCP, TCP};

    int pub_port[5];

    printf("===== OUTBOUND =====\n");
    for (int i = 0; i < 5; i++) {
        nat_outbound(priv_ip[i], priv_port[i],
                     dest_ip[i], dest_port[i],
                     proto[i], &pub_port[i]);

        printf("%s:%d -> %s:%d  ==>  %s:%d\n",
               priv_ip[i], priv_port[i],
               dest_ip[i], dest_port[i],
               PUBLIC_IP, pub_port[i]);
    }

    printf("\n===== INBOUND =====\n");
    for (int i = 0; i < 5; i++) {
        char resolved_ip[IP_LEN];
        int resolved_port;

        if (nat_inbound(pub_port[i],
                        dest_ip[i], dest_port[i],
                        proto[i],
                        resolved_ip, &resolved_port) == 0) {

            printf("%s:%d -> %s:%d  ==>  %s:%d\n",
                   dest_ip[i], dest_port[i],
                   PUBLIC_IP, pub_port[i],
                   resolved_ip, resolved_port);
        } else {
            printf("Packet dropped\n");
        }
    }

    return 0;
}


