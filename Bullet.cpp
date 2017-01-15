//
//  Bullet.cpp
//  SDL_REAL
//
//  Created by ShiLin on 1/14/17.
//  Copyright © 2017 lin. All rights reserved.
//

#include "Bullet.hpp"

Bullet::Bullet(int posX, int posY, SDL_Renderer *renderTarget, int direction, int range) {
    this -> posX = posX + 10;
    this -> posY = posY;
    bulletSurface = IMG_Load("bullet.png");
    bulletTexture = SDL_CreateTextureFromSurface(renderTarget, bulletSurface);
    SDL_FreeSurface(bulletSurface);
    SDL_QueryTexture(bulletTexture, 0, 0, &originWidth, &originHeight);
    fitWidth = originWidth/8;
    fitHeight = originHeight/8;
    sourceRect = {originWidth - fitWidth, 4 * fitHeight, fitWidth, fitHeight};
    desRect = {posX, posY, fitWidth, fitHeight};
    this -> direction = direction;
    this -> range = range;
    dead = false;
}

Bullet::~Bullet() {
    
};

bool Bullet::Update(int speed, float delta) {
    switch (direction) {
        case 0:
            posX = posX <= 0 ? 0 : (posX - speed*delta);
            dead = posX == 0;
            break;
        case 1:
            posY = posY <= 0 ? 0 : (posY - speed*delta);
            dead = posY == 0;
            break;
        case 2:
            posX = posX >= 800 ? 800 : (posX + speed*delta);
            dead = posX == 800;
            break;
        case 3:
            posY = posY >= 800 ? 800 : (posY + speed*delta);
            dead = posY == 800;
            break;
        default:
            break;
    }
    
    desRect = {posX, posY, fitWidth, fitHeight};
    
    return true;
}

bool Bullet::Draw(SDL_Renderer *targetRender) {
    if (dead) {
        SDL_DestroyTexture(bulletTexture);
        return false;
    } else {
        SDL_RenderCopy(targetRender, bulletTexture, &sourceRect, &desRect);
        return true;
    }

}
