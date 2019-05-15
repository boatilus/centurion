#pragma once
#include <SDL_events.h>
#include <SDL_keycode.h>
#include <memory>
#include "ctn_action.h"
#include "ctn_key_stroke_interface.h"
#include "ctn_key_trigger.h"

namespace centurion {
namespace events {

/**
\brief The KeyStroke class represents an key controlled action.
\since 1.0.0
*/
class KeyStroke final : public IKeyStroke {
 private:
  IAction_sptr action;
  KeyTrigger trigger;
  SDL_Keycode keycode;
  bool isRepeatable;

  bool ShouldExecute(const Event& e);

 public:
  /**
  \param keycode - the key code of the key that will trigger the KeyStroke.
  \param action - a pointer to the IAction instance that will be associated with
  the KeyStroke.
  \param trigger - the value that specifies the moment of activation.
  \since 1.0.0
  */
  KeyStroke(SDL_Keycode keycode, IAction_sptr action, KeyTrigger trigger);

  ~KeyStroke();

  /**
  \brief Updates this KeyStroke by comparing it to the supplied event.
  \param event - The event that will be checked.
  \since 1.0.0
  */
  void Update(const Event& event) override;

  /**
  \brief Programmatically triggers the IAction related to this KeyStroke.
  \since 1.0.0
  */
  void Trigger() override;

  /**
  \brief Assigns whether or not this KeyStroke may be continously triggered by
  holding down the related key. This is only applicable if this KeyStroke is
  triggered when the related key is PRESSED. By default, all KeyStrokes have
  this set to FALSE.
  \param isRepeatable - the value dictating whether this KeyStroke is
  repeatable.
  \since 1.0.0
  */
  void SetRepeatable(bool isRepeatable) noexcept override;

  /**
  \brief Indicates whether or not this KeyStroke is repeatable.
  \since 1.0.0
  */
  inline bool IsRepeatable() const noexcept override { return isRepeatable; }

  /**
  \brief Creates and returns a shared pointer to an IKeyStroke instance.
  \param keycode - the key code of the key that will trigger the IKeyStroke.
  \param action - a pointer to the IAction instance that will be associated with
  the IKeyStroke.
  \param trigger - the value that specifies the moment of activation.
  \since 1.0.0
  */
  static IKeyStroke_sptr CreateShared(SDL_Keycode keycode, IAction_sptr action,
                                      KeyTrigger trigger);

  /**
  \brief Creates and returns a unique pointer to an IKeyStroke instance.
  \param keycode - the key code of the key that will trigger the IKeyStroke.
  \param action - a pointer to the IAction instance that will be associated with
  the IKeyStroke.
  \param trigger - the value that specifies the moment of activation.
  \since 1.0.0
  */
  static IKeyStroke_uptr CreateUnique(SDL_Keycode keycode, IAction_sptr action,
                                      KeyTrigger trigger);
};

}  // namespace events
}  // namespace centurion