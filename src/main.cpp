/************************************************************
 *                                                           *
 *        _____   _       _____   _____   _____   _   _      *
 *       |  ___| | |     /  _  \ |  _  | |  _  | | | | |     *
 *       | |_    | |     | |_| | | |_| | | |_| | | |_| |     *
 *       |  _|   | |     |  _  | |  ___| |  ___| |____ |     *
 *       | |     | |___  | | | | | |     | |      ___| |     *
 *       |_|     |_____| |_| |_| |_|     |_|     |_____|     *
 *                                                           *
 *   _______   _______   ____     _____     ____             *
 *  |_   _  \ |__   __| |  _ \   |  _  \   |  __|            *
 *    | |_) /    | |    | |_) |  | | \  \  | |__             *
 *    |  _ (     | |    |  _ <   | |  |  | |__  |            *
 *   _| |_) \  __| |__  | | \ \  | |_/  /   __| |            *
 *  |_______/ |_______| |_|  \_\ |_____/   |____|            *
 *                                                           *
 *                                                           *
 *                                                           *
 *                        -by                                *
 *                                                           *
 *                                                           *
 *                 ______   ____     ____                    *
 *                /  ____) |  _ \   |  _ \                   *
 *          ____ (  (____  | |_) )  | |_) )                  *
 *         /  __) \____  \ |  _ <   |  __/                   *
 *        (  (__   ____)  )| | \ \  | |                      *
 *         \____) (______/ |_|  \_\ |_|                      *
 *                                                           *
 *                                                           *
 *************************************************************/

#include "Flappy-Bird/Flappy-Bird.h"

int main(int argc, char *argv[]) {
  FlappyBird *flappyBird = FlappyBird::getInstance();
  flappyBird->run();

  return 0;
}
