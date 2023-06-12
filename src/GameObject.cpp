#include "GameObject.hpp"

#include <iostream>

GameObject::GameObject(SDL_Renderer* renderer, int xPos, int yPos, int width,
                       int height, ObjectType type, int frame, std::string tag) {
    mXPos = xPos;
    mYPos = yPos;
    mWidth = width;
    mHeight = height;
    mFrame = frame;
    mXVelocity = 0;
    mYVelocity = 0;
    mSpeed = 3;
    mCollisionDirection = new int[4]();
    mRenderer = renderer;
    mObjectType = type;
    mTag = tag;
}

GameObject::~GameObject() {
    delete mCollisionDirection;
}

void GameObject::AddEvent(SDL_Event& e) {
    mEvents.push_back(e);
}

void GameObject::Update() {
    for (int i = 0; i < mComponents.size(); i++) {
        mComponents[i]->Update(*this);
    }
}

void GameObject::Render() {
    for (int i = 0; i < mComponents.size(); i++) {
        mComponents[i]->Render(*this, mRenderer);
    }
}

int GameObject::GetXVelocity() {
    return mXVelocity;
}

void GameObject::SetXVelocity(int velocity) {
    mXVelocity = velocity;
}

int GameObject::GetYVelocity() {
    return mYVelocity;
}

void GameObject::SetYVelocity(int velocity) {
    mYVelocity = velocity;
}

int* GameObject::GetCollisionDirections() {
    return mCollisionDirection;
}

void GameObject::SetCollisionDirections(int* collisionDirection) {
    std::copy(collisionDirection, collisionDirection + 4, mCollisionDirection);
    delete collisionDirection;
}

int GameObject::GetX() {
    return mXPos;
}

void GameObject::SetX(int xPos) {
    mXPos = xPos;
}

int GameObject::GetY() {
    return mYPos;
}

void GameObject::SetY(int yPos) {
    mYPos = yPos;
}

int GameObject::GetWidth() {
    return mWidth;
}

int GameObject::GetHeight() {
    return mHeight;
}

int GameObject::GetFrame() {
    return mFrame;
}

void GameObject::SetFrame(int frame) {
    mFrame = frame;
}

std::string GameObject::GetSequence() {
    return mSequence;
}

void GameObject::SetSequence(std::string sequence) {
    mSequence = sequence;
}

int GameObject::GetSpeed() {
    return mSpeed;
}

void GameObject::SetSpeed(int speed) {
    mSpeed = speed;
}

bool GameObject::GetIsDeleted() {
    return mIsDeleted;
}

void GameObject::SetIsDeleted(bool isDeleted) {
    mIsDeleted = isDeleted;
}

ObjectType GameObject::GetObjectType() {
    return mObjectType;
}
void GameObject::SetObjectType(ObjectType objectType) {
    mObjectType = objectType;
}

void GameObject::AddComponent(Component* component) {
    mComponents.push_back(component);
}

std::vector<SDL_Event> GameObject::GetEvents() {
    return mEvents;
}

std::string GameObject::GetTag() {
    return mTag;
}