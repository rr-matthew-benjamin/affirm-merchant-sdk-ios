//
//  AffirmEligibilityViewController.h
//  AffirmSDK
//
//  Created by Victor Zhu on 2020/9/21.
//  Copyright © 2020 Affirm, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

@class AffirmCheckout;
@protocol AffirmCheckoutDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface AffirmEligibilityViewController : UIViewController

/**
 The delegate which handles checkout events.
 */
@property (nonatomic, weak) id<AffirmCheckoutDelegate> delegate;

/**
 The checkout object used to start the checkout process.
 */
@property (nonatomic, copy, readonly) AffirmCheckout *checkout;

/**
 Use VCN Checkout
 */
@property (nonatomic, readonly) BOOL useVCN;

/**
 Get Reason Codes
 */
@property (nonatomic, readonly) BOOL getReasonCodes;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil
                         bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;

/**
 Initializer. See properties for more details. UseVCN is NO as default
 
 @param delegate A delegate object which responds to the checkout events created by the view controller.
 @param checkout A checkout object which contains information about the customer and the purchase.
 @param useVCN A boolean which determines whether the checkout flow should use virtual card network to handle the checkout
 @param getReasonCodes A boolean which determines whether to return the reason why the checkout was canceled
 @return The newly created checkout view controller.
 */
- (instancetype)initWithDelegate:(id<AffirmCheckoutDelegate>)delegate
                        checkout:(AffirmCheckout *)checkout
                          useVCN:(BOOL)useVCN
                  getReasonCodes:(BOOL)getReasonCodes
NS_SWIFT_NAME(init(delegate:checkout:useVCN:getReasonCodes:)) NS_DESIGNATED_INITIALIZER;

+ (UINavigationController *)startCheckoutWithNavigation:(AffirmCheckout *)checkout
                                                 useVCN:(BOOL)useVCN
                                         getReasonCodes:(BOOL)getReasonCodes
                                               delegate:(nonnull id<AffirmCheckoutDelegate>)delegate
NS_SWIFT_NAME(startNavigation(checkout:useVCN:getReasonCodes:delegate:));

/**
 Convenience constructor starts the checkout process and notifies delegate regarding checkout events
 
 @param checkout A checkout object which contains information about the customer and the purchase.
 @param useVCN A boolean which determines whether the checkout flow should use virtual card network to handle the checkout
 @param getReasonCodes A boolean which determines whether to return the reason code when a checkout is canceled
 @param delegate A delegate object which responds to the checkout events created by the view controller.
 @return The newly created checkout view controller.
 */
+ (AffirmEligibilityViewController *)startCheckout:(AffirmCheckout *)checkout
                                            useVCN:(BOOL)useVCN
                                    getReasonCodes:(BOOL)getReasonCodes
                                          delegate:(id<AffirmCheckoutDelegate>)delegate
NS_SWIFT_NAME(start(checkout:useVCN:getReasonCodes:delegate:));

@end

NS_ASSUME_NONNULL_END
