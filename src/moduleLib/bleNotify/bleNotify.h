#ifndef __BLE_NOTIFY_H__
#define __BLE_NOTIFY_H__

enum ActionType {USING, CLEANING, EMPTYING}

void bleNotify(ActionType type);

#endif