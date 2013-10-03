//----------------------------------------------------------------------------------------
/**
 * \file       pxxloader.cpp
 * \author     Vonasek Lubos
 * \date       2013/04/20
 * \brief      Loading and storing sequences of PNG
*/
//----------------------------------------------------------------------------------------

#include "stdafx.h"

/**
 * @brief destruct removes texture from memory is there is no more instance
 */
void pxxloader::destruct() {
  instanceCount--;
  if (instanceCount == 0) {
      for (unsigned int i = 0; i < anim.size(); i++) {
          anim[anim.size() - 1]->destruct();
          anim.pop_back();
      }
  }
}

/**
 * @brief bmp24 loads texture from png file
 * @param filename is name of file
 * @param alpha is amount of blending
 */
pxxloader::pxxloader(const char* filename, float alpha) {
    anim = *(new std::vector<pngloader*>());
    currentFrame = 0;
    currentMultiFrame = 0;
    char* ext = getExtension(filename);
    int count = (ext[1] - '0') * 10 + ext[2] - '0';
    char file[255];
    strcpy(file, filename);
    for (int i = 0; i <= count; i++) {
        file[strlen(filename) - 1] = i % 10 + '0';
        file[strlen(filename) - 2] = i / 10 + '0';
        anim.push_back(new pngloader(file, alpha));
        anim[anim.size() - 1]->instanceCount = 1;
        anim[anim.size() - 1]->texturename[0] = '\0';
    }
    transparent = true;
    multiFrame = anim.size() / 50;
    if (multiFrame < 1)
        multiFrame = 1;
}

/**
 * @brief apply applies current texture
 */
void pxxloader::apply() {
    currentMultiFrame++;
    if (currentMultiFrame == multiFrame) {
        currentMultiFrame = 0;
        currentFrame++;
    }
    if (currentFrame == anim.size()) {
        currentFrame = 0;
    }
    anim[currentFrame]->apply();
}

void pxxloader::setFrame(int frame) {
    currentFrame = frame;
}
