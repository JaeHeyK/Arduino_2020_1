#ifndef __BLE_NOTIFY_H__
#define __BLE_NOTIFY_H__

typedef enum _ActionType {
  USING,
  CLEANING,
  EMPTYING
} ActionType;

void bleNotify(int type);
void bleNotify(ActionType type);

#endif