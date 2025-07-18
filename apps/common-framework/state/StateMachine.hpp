/*Copyright 2025 Kamlesh Singh
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef COMMON_FRAMEWORK_STATE_MACHINE_HPP
#define COMMON_FRAMEWORK_STATE_MACHINE_HPP

#include <map>
#include <memory>

#include "IStateMachine.hpp"
#include "IState.hpp"
#include "ApplicationState.hpp"


template<typename StateEnum, typename EventEnum>
class StateMachine : public IStateMachine<StateEnum, EventEnum> {
public:
    explicit StateMachine(StateEnum initialState);

    void addState(StateEnum type, std::unique_ptr<IState<StateEnum, EventEnum>> state) override;
    void transitionTo(StateEnum newStateEnum) override;
    void handleEvent(EventEnum event) override;
    StateEnum getCurrentState() const override;

private:
    StateEnum currentStateEnum_;
    IState<StateEnum, EventEnum>* currentState_ = nullptr; // Raw pointer to current state (owned by map)
    std::map<StateEnum, std::unique_ptr<IState<StateEnum, EventEnum>>> states_;
};

#endif // COMMON_FRAMEWORK_STATE_MACHINE_HPP