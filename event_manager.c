#include<stdio.h>

#define MAX_EVENTS 20
#define MAX_MODULES 20

int subscriptions[MAX_MODULES][MAX_EVENTS];
int numevents, nummodules;

void init_subscriptions() {
    for(int i = 0; i < MAX_MODULES; i++) {
        for(int j = 0; j < MAX_EVENTS; j++) {
            subscriptions[i][j] = 0;
        }
    }
}

void triggerEvent(int event) {
    printf("\nEvent %d occurred\n", event);
    int found = 0;

    for(int i = 0; i < nummodules; i++) {
        if(subscriptions[i][event] == 1) {
            printf("Module %d handled event %d\n", i, event);
            found = 1;
        }
    }

    if(found == 0) {
        printf("No module subscribed to this event\n");
    }
}

void subscribe(int event, int module) {
    subscriptions[module][event] = 1;
    printf("Module %d subscribed to event %d\n", module, event);
}

void unsubscribe(int event, int module) {
    subscriptions[module][event] = 0;
    printf("Module %d unsubscribed from event %d\n", module, event);
}

int main() {
    init_subscriptions();

    printf("Enter number of events: ");
    scanf("%d", &numevents);

    printf("Enter number of modules: ");
    scanf("%d", &nummodules);

    for(int i = 0; i < nummodules; i++) {
        int count;
        printf("\nModule %d - Number of events for this module: ", i);
        scanf("%d", &count);

        printf("Enter the event numbers for module %d: ", i);
        for(int j = 0; j < count; j++) {
            int e;
            scanf("%d", &e);
            if(e >= 0 && e < numevents)
                subscriptions[i][e] = 1;
        }
    }

    int choice;
    while(1) {
        printf("\n1. Trigger event");
        printf("\n2. Subscribe event");
        printf("\n3. Unsubscribe event");
        printf("\n4. Exit");
        printf("\nChoice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            int event;
            printf("Enter event: ");
            scanf("%d", &event);
            if(event >= 0 && event < numevents)
                triggerEvent(event);
            else
                printf("Invalid event\n");
        }
        else if(choice == 2) {
            int module, event;
            printf("Enter module: ");
            scanf("%d", &module);
            printf("Enter event: ");
            scanf("%d", &event);
            if(module < nummodules && event < numevents)
                subscribe(event, module);
        }
        else if(choice == 3) {
            int module, event;
            printf("Enter module: ");
            scanf("%d", &module);
            printf("Enter event: ");
            scanf("%d", &event);
            if(module < nummodules && event < numevents)
                unsubscribe(event, module);
        }
        else if(choice == 4) {
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}

